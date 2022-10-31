type
  node1=record
    x,flow,next:longint;
  end;
  node2=record
    x,y,p:longint;
  end;
var
  a,b,q,d,g,nrl:array[0..500]of longint;
  data:array[0..100000]of node1;
  ans:Array[1..101,1..101]of longint;
  edge:array[1..500]of node2;
  sum1,sum2,n,m,tot,ss,ee:longint;
procedure addedge(x,y,flow:longint);
begin
  inc(tot);
  data[tot].x:=y;
  data[tot].flow:=flow;
  data[tot].next:=g[x];
  g[x]:=tot;

  inc(tot);
  data[tot].x:=x;
  data[tot].flow:=0;
  data[tot].next:=g[y];
  g[y]:=tot;
end;
procedure bfs;
var
  head,tail,i,x,p:longint;
begin
  move(g,nrl,sizeof(g));
  fillchar(d,sizeof(d),255);
  head:=0;
  tail:=1;
  q[1]:=ss;
  d[ss]:=0;
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
function min(x,y:longint):longint;
begin
  if x<y then exit(x) else exit(y);
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
      t:=get(data[nrl[x]].x,min(data[nrl[x]].flow,flow));
      if t>0 then
      begin
        dec(data[nrl[x]].flow,t);
        inc(data[nrl[x]xor 1].flow,t);
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
  bfs;
  flow:=0;
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
procedure init;
var
  x,y,i,j:longint;
begin
  read(n,m);
  ss:=0;
  ee:=2*n+1;
  tot:=-1;
  fillchar(g,sizeof(g),255);
  sum1:=0;
  for i:=1 to n do
  begin
    read(x);
    sum1:=sum1+x;
    a[i]:=x;
    addedge(ss,i,x);
    addedge(i,n+i,x);
  end;
  sum2:=0;
  for i:=1 to n do
  begin
    read(x);
    b[i]:=x;
    sum2:=sum2+x;
    addedge(n+i,ee,x);
  end;
  for i:=1 to m do
  begin
    read(edge[i].x,edge[i].y);
    edge[m+i].x:=edge[i].y;
    edge[m+i].y:=edge[i].x;
  end;
  m:=m*2;
  for i:=1 to m do
  begin
    edge[i].p:=tot+1;
    addedge(edge[i].x,edge[i].y+n,2147483647);
  end;
end;
procedure main;
var
  i,j:longint;
begin
  if (dinic<>sum2)or(sum1<>sum2) then
  begin
    writeln('NO');
    exit;
  end;
  writeln('YES');
  fillchar(ans,sizeof(ans),0);
  for i:=1 to m do
    inc(ans[edge[i].x,edge[i].y],data[edge[i].p xor 1].flow);
  for i:=1 to n do
  begin
    ans[i,i]:=a[i];
    for j:=1 to n do
      if j<>i then dec(ans[i,i],ans[i,j]);
  end;
  for i:=1 to n do
  begin
    write(ans[i,1]);
    for j:=2 to n do write(' ',ans[i,j]);
    writeln;
  end;
end;
begin
 
  init;
  main;

end.