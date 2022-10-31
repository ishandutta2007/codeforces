var
  f:array[0..600,0..600]of int64;
  a:array[0..600]of longint;
  n:longint;
const
  inf=1000000007;
function dfs(l,r:longint):int64;
var
  i:longint;
begin
  if l=r then
  begin
    f[l,r]:=1;
    exit(1);
  end;
  if f[l,r]<>-1 then exit(f[l,r]);
  f[l,r]:=dfs(l+1,r);
  for i:=l+1 to r-1 do
    if a[l+1]<a[i+1] then
      f[l,r]:=(f[l,r]+dfs(l+1,i)*dfs(i,r)mod inf)mod inf;
  exit(f[l,r]);
end;
var
  i:longint;
begin

  readln(n);
  for i:=1 to n do read(a[i]);
  readln;
  fillchar(f,sizeof(f),255);
  writeln(dfs(1,n));

end.