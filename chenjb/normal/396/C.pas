type
  node=record
    x,next:longint;
  end;
var
  a,b:array[1..500000]of int64;
  data:array[1..700000]of node;
  g:array[1..400000]of longint;
  dep,ru,chu:array[1..400000]of longint;
  n,q,tot:longint;
const
  inf=1000000007;
function lowbit(x:longint):longint;
begin
  exit(x and (-x));
end;
procedure insert1(x:longint; k:int64);
begin
  while x<=n do
  begin
    a[x]:=(a[x]+k)mod inf;
    x:=x+lowbit(x);
  end;
end;
procedure insert2(x:longint; k:int64);
begin
  while x<=n do
  begin
    b[x]:=(b[x]+k)mod inf;
    x:=x+lowbit(x);
  end;
end;
function getsum1(x:longint):int64;
var
  ans:int64;
begin
  ans:=0;
  while x>0 do
  begin
    ans:=(ans+a[x])mod inf;
    x:=x-lowbit(x);
  end;
  exit(ans);
end;
function getsum2(x:longint):int64;
var
  ans:int64;
begin
  ans:=0;
  while x>0 do
  begin
    ans:=(ans+b[x])mod inf;
    x:=x-lowbit(x);
  end;
  exit(ans);
end;
procedure addedge(x,y:longint);
begin
  inc(tot);
  data[tot].x:=y;
  data[tot].next:=g[x];
  g[x]:=tot;
end;
procedure dfs(x,depp:longint);
var
  p:longint;
begin
  inc(tot);
  ru[x]:=tot;
  dep[x]:=depp;
  p:=g[x];
  while p<>-1 do
  begin
    dfs(data[p].x,depp+1);
    p:=data[p].next;
  end;
  chu[x]:=tot;
end;
procedure init;
var
  i,j,x,y:longint;
begin
  readln(n);
  fillchar(g,sizeof(g),255);
  tot:=0;
  for i:=2 to n do
  begin
    read(x);
    addedge(x,i);
  end;
  tot:=0;
  dfs(1,1);
end;
procedure main;
var
  i,j,v,x,y,way:longint;
  t,ans,k:int64;
begin
  readln(q);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  for i:=1 to q do
  begin
    read(way);
    if way=1 then
    begin
      readln(v,x,k);
      t:=(x+(dep[v]*k mod inf))mod inf;
      insert1(chu[v]+1,-t);
      insert1(ru[v],t);
      insert2(chu[v]+1,-k);
      insert2(ru[v],k);
    end
    else
    begin
      readln(x);
      ans:=getsum1(ru[x])-(dep[x]*getsum2(ru[x]) mod inf);
      ans:=((ans mod inf)+inf)mod inf;
      writeln(ans);
    end;
  end;
end;
begin
  
  init;
  main;

end.