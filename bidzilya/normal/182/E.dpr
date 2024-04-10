program task_1;

{$APPTYPE CONSOLE}
uses Math, SysUtils;
const md = round(1e9)+7;
var n,l,i,j,k,m: integer;
    a,b,tp: array[1..222]of integer;
    dp: array[0..3333,0..222]of integer;

begin
  read(n,l);
  m:=0;
  for i:=1 to n do begin
    read(j,k);
    inc(m);
    tp[m]:=i;
    a[m]:=j;
    b[m]:=k;
    if (j<>k)then begin
      inc(m);
      tp[m]:=i;
      a[m]:=k;
      b[m]:=j;
    end;
  end;
  fillchar(dp,sizeof(dp),0);
  dp[0,0]:=1;
  for i:=1 to l do
    for j:=1 to m do
      if (a[j]<=i)then
        for k:=0 to m do
          if (k=0)or((tp[j]<>tp[k])and(a[j]=b[k]))then
            dp[i,j]:=(dp[i,j]+dp[i-a[j],k])mod md;
  k:=0;
  for i:=1 to m do
    k:=(k+dp[l,i])mod md;
  write(k);
end.