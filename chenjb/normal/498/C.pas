type
  node1=record
    x,flow,next:longint;
  end;
  node2=record
    x,y:longint;
    end;
var
  d,q,time,nrl,g:array[0..300]of longint;
  data:array[0..100000]of node1;
  pair:array[1..200]of node2;
  a:array[1..300]of longint;
  prime:array[1..50000]of boolean;
  ss,ee,n,m,tot:longint;
procedure addedge(x,y,flow:longint);
begin
  inc(tot);
  data[tot].x:=y;
  data[tot].next:=g[x];
  data[tot].flow:=flow;
  g[x]:=tot;

  inc(tot);
  data[tot].x:=x;
  data[tot].next:=g[y];
  data[tot].flow:=0;
  g[y]:=tot;
end;
procedure swap(var x,y:longint);
var
  t:longint;
begin
  t:=x;
  x:=y;
  y:=t;
end;
procedure init;
var
  i,j:longint;
begin
  read(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do
  begin
    read(pair[i].x,pair[i].y);
    if pair[i].x mod 2=0 then swap(pair[i].x,pair[i].y);
  end;
end;
procedure getprime;
var
  i,j:longint;
begin
  fillchar(prime,sizeof(prime),true);
  prime[1]:=false;
  for i:=2 to 50000 do
    if prime[i] then
      for j:=2 to 50000 div i do
      begin
        if j*i>50000 then break;
        prime[i*j]:=false;
      end;
end;
function min(x,y:longint):longint;
begin
  if x<y then exit(x) else exit(y);
end;
procedure bfs;
var
  head,tail,i,x,p:longint;
begin
  fillchar(d,sizeof(d),255);
  move(g,nrl,sizeof(g));
  head:=0;
  tail:=1;
  d[ss]:=0;
  q[1]:=ss;
  while head<tail do
  begin
    inc(head);
    x:=q[head];
    p:=g[x];
    while p<>-1 do
    begin
      if (data[p].flow>0)and(d[data[p].x]=-1)then
      begin
        d[data[p].x]:=d[x]+1;
        if data[p].x=ee then exit;
        inc(tail);
        q[tail]:=data[p].x;
      end;
      p:=data[p].next;
    end;
  end;
end;
function get(x,flow:longint):longint;
var
  t:longint;
begin
  if x=ee then exit(flow);
  while nrl[x]<>-1 do
  begin
    if (data[nrl[x]].flow>0)and(d[x]+1=d[data[nrl[x]].x])then
    begin
      t:=get(data[nrl[x]].x,min(flow,data[nrl[x]].flow));
      if t>0 then
      begin
        dec(data[nrl[x]].flow,t);
        inc(data[nrl[x] xor 1].flow,t);
        exit(t);
      end;
    end;
    nrl[x]:=data[nrl[x]].next;
  end;
  exit(0);
end;
function dinic:longint;
var
  t,flow:longint;
begin
  flow:=0;
  bfs;
  while d[ee]<>-1 do
  begin
    t:=get(ss,2147483647);
    while t>0 do
    begin
      flow:=flow+t;
      t:=get(ss,2147483647);
    end;
    bfs;
  end;
  exit(flow);
end;
function solve(p:longint):longint;
var
  i:longint;
begin
  fillchar(g,sizeof(g),255);
  tot:=-1;
  for i:=1 to n do
  begin
    time[i]:=0;
    while a[i] mod p=0 do
    begin
      inc(time[i]);
      a[i]:=a[i] div p;
    end;
  end;
  for i:=1 to n do
    if i mod 2=1 then addedge(ss,i,time[i])
    else addedge(i,ee,time[i]);
  for i:=1 to m do
    addedge(pair[i].x,pair[i].y,min(time[pair[i].x],time[pair[i].y]));
  exit(dinic);
end;
procedure main;
var
  ans,i:longint;
begin
  ss:=0;
  ee:=n+1;
  getprime;
  ans:=0;
  for i:=2 to 50000 do
    if prime[i] then ans:=ans+solve(i);

  fillchar(g,sizeof(g),255);
  tot:=-1;
  for i:=1 to n do
    if i mod 2=1 then addedge(ss,i,1)
    else addedge(i,ee,1);
  for i:=1 to m do
    if (a[pair[i].x]=a[pair[i].y])and(a[pair[i].x]<>1)then
      addedge(pair[i].x,pair[i].y,1);
  ans:=ans+dinic;
  writeln(ans);
end;
begin

  init;
  main;

end.