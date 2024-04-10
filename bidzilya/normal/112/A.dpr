program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var s1,s2: string;
    i,j: integer;

begin
  readln(s1);
  for i:=1 to length(s1)do
    if (s1[i]>='A')and(s1[i]<='Z')then
      s1[i]:=chr(ord(s1[i])+32);
  readln(s2);
  for i:=1 to length(s2)do
    if (s2[i]>='A')and(s2[i]<='Z')then
      s2[i]:=chr(ord(s2[i])+32);
  if (s1<s2)then
    write(-1)
  else
  if (s2<s1)then
    write(1)
  else
    write(0);
end.