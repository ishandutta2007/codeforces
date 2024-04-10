var
  s:ansistring;
  sum,fac,inv:array[0..100005]of int64;
  i,n,m:longint;
  ans,t,k:int64;
const
  inf=1000000007;
function c(n,m:int64):int64;
var
  t:int64;
begin
  if (m>n)or(m<0)then exit(0);
  t:=(fac[n]*inv[m] mod inf)*inv[n-m] mod inf;
  exit(t);
end;
begin

  fac[0]:=1;
  fac[1]:=1;
  inv[0]:=1;
  inv[1]:=1;
  for i:=2 to 100005 do
  begin
    fac[i]:=fac[i-1]*i mod inf;
    inv[i]:=(inf-inf div i)*inv[inf mod i] mod inf;
  end;
  for i:=1 to 100005 do
    inv[i]:=inv[i]*inv[i-1] mod inf;

  readln(n,m);
  readln(s);
  sum[i-1]:=0;
  k:=1;
  for i:=1 to n do
  begin
    sum[i]:=(sum[i-1]+k*c(n-i-1,m-1) mod inf)mod inf;
    k:=k*10 mod inf;
  end;
  ans:=0;
  k:=1;
  for i:=n downto 1 do
  begin
    t:=ord(s[i])-48;
    ans:=(ans+(t*k mod inf)*c(i-1,m)mod inf)mod inf;
    ans:=(ans+t*sum[n-i]mod inf)mod inf;
    k:=k*10 mod inf;
  end;
  writeln(ans);
 
end.