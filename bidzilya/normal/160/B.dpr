program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var buf,n,i,j: integer;
    a,b: array[1..100]of integer;
    s: string;
    ok1,ok2: boolean;


begin
  readln(n);
  readln(s);
  for i:=1 to n do
    a[i]:=ord(s[i])-ord('0');
  for i:=1 to n do
    b[i]:=ord(s[n+i])-ord('0');
  for i:=1 to n do
    for j:=i+1 to n do
      if (a[j]<a[i])then begin
        buf:=a[i];a[i]:=a[j];a[j]:=buf;
      end;
  for i:=1 to n do
    for j:=i+1 to n do
      if (b[j]<b[i])then begin
        buf:=b[i];b[i]:=b[j];b[j]:=buf;
      end;
  ok1:=true;
  for i:=1 to n do
    if (a[i]<=b[i])then begin
      ok1:=false;
      break;
    end;
  ok2:=true;
  for i:=1 to n do
    if (a[i]>=b[i])then begin
      ok2:=false;
      break;
    end;
  if (ok1)or(ok2)then
    write('YES')
  else
    write('NO');
end.