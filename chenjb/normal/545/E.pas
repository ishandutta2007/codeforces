type
  node=record
    p,x,next:longint;
    w:int64;
  end;
var
  prew:array[1..400000]of int64;
  pre:array[1..400000]of longint;
  data:array[1..700000]of node;
  g:array[1..400000]of longint;
  ans:array[1..400000]of int64;
  q:array[1..2000000]of longint;
  d:array[1..400000]of int64;
  v:array[1..400000]of boolean;
  start,n,m,tot:longint;
procedure addedge(p,x,y,w:longint);
begin
  inc(tot);
  data[tot].x:=y;
  data[tot].w:=w;
  data[tot].p:=p;
  data[tot].next:=g[x];
  g[x]:=tot;
end;
procedure qsort(left,right:longint);
var
  i,j:longint;
  t,mid:int64;
begin
  if left>=right then exit;
  i:=left;
  j:=right;
  mid:=ans[(i+j)div 2];
  repeat
    while ans[i]<mid do inc(i);
    while ans[j]>mid do dec(j);
    if i<=j then
    begin
      t:=ans[i];
      ans[i]:=ans[j];
      ans[j]:=t;
      inc(i);
      dec(j);
    end;
  until i>j;
  qsort(left,j);
  qsort(i,right);
end;
procedure init;
var
  i,j,x,y,w:longint;
begin
  readln(n,m);
  fillchar(g,sizeof(g),255);
  tot:=0;
  for i:=1 to m do
  begin
    readln(x,y,w);
    addedge(i,x,y,w);
    addedge(i,y,x,w);
  end;
  readln(start);
end;
procedure spfa;
var
  head,tail,i,x,p:longint;
  sum:int64;
begin
  head:=0;
  tail:=1;
  q[1]:=start;
  for i:=1 to n do
  begin
    v[i]:=false;
    d[i]:=2147483647000000;
    prew[i]:=2147483647000000;
    pre[i]:=-1;
  end;
  v[start]:=true;
  d[start]:=0;
  while head<>tail do
  begin
    head:=(head mod 2000000)+1;
    x:=q[head];
    v[x]:=false;
    p:=g[x];
    while p<>-1 do
    begin
      if (d[x]+data[p].w<d[data[p].x])or
        ((d[x]+data[p].w=d[data[p].x])and(data[p].w<prew[data[p].x]))then
      begin
        d[data[p].x]:=d[x]+data[p].w;
        prew[data[p].x]:=data[p].w;
        pre[data[p].x]:=data[p].p;
        if not v[data[p].x] then
        begin
          v[data[p].x]:=true;
          tail:=(tail mod 2000000)+1;
          q[tail]:=data[p].x;
        end;
      end;
      p:=data[p].next;
    end;
  end;
  sum:=0;
  tot:=0;
  for i:=1 to n do
    if i<>start then
    begin
      inc(tot);
      ans[tot]:=pre[i];
      sum:=sum+prew[i];
    end;
 // qsort(1,tot);
  writeln(sum);
  if tot=0 then exit;
  write(ans[1]);
  for i:=2 to tot do write(' ',ans[i]);
  writeln;
end;
begin

  init;
  spfa;
  
end.