type
  node=record
    x,next:longint;
  end;
const
  inf=1000000007;
var
  color,g:array[0..110000]of longint;
  data:array[1..300001]of node;
  f:array[0..110000,0..1]of int64;
  tot,n,i,x:longint;
procedure addedge(x,y:longint);
begin
  inc(tot);
  data[tot].x:=y;
  data[tot].next:=g[x];
  g[x]:=tot;
end;
procedure dfs(x,pre:longint);
var
  p:longint;
begin
  if color[x]=1 then f[x,1]:=1 else f[x,0]:=1;
  p:=g[x];
  while p<>-1 do
  begin
    if data[p].x<>pre then
    begin
      dfs(data[p].x,x);
      f[x,1]:=(f[x,1]*(f[data[p].x,0]+f[data[p].x,1])+f[x,0]*f[data[p].x,1])mod inf;
      f[x,0]:=(f[x,0]*(f[data[p].x,0]+f[data[p].x,1]))mod inf;
    end;
    p:=data[p].next;
  end;
end;
begin

  read(n);
  fillchar(g,sizeof(g),255);
  tot:=0;
  for i:=1 to n-1 do
  begin
    read(x);
    addedge(x,i);
    addedge(i,x);
  end;
  for i:=0 to n-1 do read(color[i]);
  fillchar(f,sizeof(f),0);
  dfs(0,-1);
  writeln(f[0,1]);
 
end.