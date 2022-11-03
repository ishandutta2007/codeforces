program task_1;

{$apptype console}
{$r+ q+ o+}
uses
  SysUtils, Math;
var n,i,ans: integer;
    p: array[1..2000]of integer;
    used: array[1..2000]of boolean;

procedure dfs(v,len: integer);
begin
  used[v]:=true;
  if (p[v]<>-1)then
    dfs(p[v],len+1)
  else
    ans:=max(ans,len);
end;

begin
  read(n);
  for i:=1 to n do read(p[i]);
  ans:=1;
  fillchar(used,sizeof(used),false);
  for i:=1 to n do
    if (not used[i])then
      dfs(i,1);
  write(ans);
end.