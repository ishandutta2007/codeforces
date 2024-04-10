var
  ans:int64;
  time,ii,a,b,i,x:longint;
  aa,sum:array[1..5000000]of int64;
  tot:longint;
  isprime:array[1..5000000]of boolean;
  prime:Array[1..5000000]of longint;
function divide(x:longint):longint;
var
  i:longint;
  t:longint;
  xx:longint;
begin
  t:=0;
  xx:=x;
  for i:=2 to trunc(sqrt(xx)) do
    if x mod i=0 then
    begin
      while x mod i=0 do
      begin
        inc(t);
        x:=x div i;
      end;
    end;
  if x>1 then inc(t);
  exit(t);
end;
procedure prepare;
var
  i,j:longint;
begin
  tot:=0;
  fillchar(isprime,sizeof(isprime),true);
  isprime[1]:=false;
  for i:=2 to 5000000 do
  begin
    if isprime[i] then
    begin
      inc(tot);
      prime[tot]:=i;
      aa[i]:=1;
    end;
    for j:=1 to tot do
    begin
      if prime[j]*i>5000000 then break;
      isprime[prime[j]*i]:=false;
      aa[prime[j]*i]:=aa[i]+1;
      if i mod prime[j]=0 then break;
    end;
  end;
  sum[1]:=0;
  for i:=2 to 5000000 do
    sum[i]:=aa[i]+sum[i-1];
end;
begin

  prepare;
  readln(time);
  for ii:=1 to time do
  begin
    readln(a,b);
    ans:=0;
    ans:=sum[a]-sum[b];
    writeln(ans);
  end;
  close(input);
  close(output);
end.