program E;
{$APPTYPE CONSOLE}
uses Math;
var maxcost: array[1..100,0..100]of integer;
    a: array[1..100,0..100]of integer;
    l: array[1..100]of integer;
    dp: array[0..10000]of integer;
    n,m,i,j,t: integer;

procedure calc(ind: integer);
var i,j: integer;
begin
  a[ind,0]:=0;
  for i:=1 to l[ind]do
    a[ind,i]:=a[ind,i-1]+a[ind,i];
  for i:=0 to l[ind] do
    for j:=0 to l[ind] do
      if (i+j<=l[ind])then
        maxcost[ind,i+j]:=max(maxcost[ind,i+j],a[ind,i]+a[ind,l[ind]]-a[ind,l[ind]-j]);
end;

begin
  read(n,m);
  for i:=1 to n do begin
    read(l[i]);
    for j:=1 to l[i] do
      read(a[i,j]);
  end;
  fillchar(maxcost,sizeof(maxcost),0);
  for i:=1 to n do calc(i);
  fillchar(dp,sizeof(dp),-1);
  dp[0]:=0;
  for i:=1 to n do
    for j:=m downto 0 do
      if (dp[j]<>-1)then
      for t:=1 to l[i]do
        if (t+j<=m)then
          dp[j+t]:=max(dp[j+t],dp[j]+maxcost[i,t]);
  write(dp[m]);
end.