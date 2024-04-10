program task_3;

{$apptype console r+ q+ MAXSTACKSIZE 10000000}
uses Math;
const maxint = round(1e5);
      md = round(1e9)+7;
      nmax = round(1e3);
var n,m,i,j,k: integer;
    dp: array[0..nmax,0..2*nmax]of int64;
begin
  read(n,m,k);
  fillchar(dp,sizeof(dp),0);
  for i:=0 to max(n,m)do
    dp[i,0]:=1;
  for i:=1 to max(n,m)-1 do
    for j:=1 to 2*k do
      dp[i,j]:=(dp[i-1,j]+dp[i-1,j-1])mod md;
  write(dp[n-1,2*k]*dp[m-1,2*k]mod md);
end.