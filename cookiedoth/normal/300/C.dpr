program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const module=1000000007; max=1000000;
var
  fact:array[0..1000000] of Int64;
function Check(s:string;a,b:integer):Boolean;
var
  i,c:Integer;
begin
  result:=true;
  for i:=1 to Length(s) do
  begin
    c:=StrToInt(s[i]);
    if (c<>a) and (c<>b) then
    begin
      result:=false;
      exit;
    end;
  end;
end;
function qpow(x,pow:Int64):Int64;
var
  c:int64;
begin
  if pow=0 then
  begin
    Result:=1;
    exit;
  end;
  if (pow mod 2)=0 then
  begin
    c:=qpow(x,pow div 2);
    result:=(c*c) mod module;
    Exit;
  end;
  if (pow mod 2)=1 then
  begin
    c:=qpow(x,pow-1);
    Result:=(c*x) mod module;
    Exit;
  end;
end;
function Inv(x:Int64):Int64;
begin
  result:=qpow(x,module-2);
end;
function C(n,k:Int64):Int64;
var
  a:integer;
begin
  a:=(fact[k]*fact[n-k]) mod module;
  result:=(fact[n]*inv(a)) mod module;
end;
procedure CountFact;
var
  i:integer;
begin
  fact[0]:=1;
  for i:=1 to max do fact[i]:=(fact[i-1]*i) mod module;
end;
var
  a,b,n:integer;
  ans:Int64;
procedure bebebe;
var
  i,x:integer;
  s:string;
begin
  ans:=0;
  CountFact;
  for i:=0 to n do
  begin
    x:=i*a+(n-i)*b;
    s:=IntToStr(x);
    if Check(s,a,b) then
    begin
      Inc(ans,C(n,i));
      ans:=ans mod module;
    end;
  end;
end;
begin
  Readln(a,b,n);
  bebebe;
  write(Ans);
end.