program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var s1,s2: string;
    i: integer;
begin
  readln(s1);
  readln(s2);
  for i:=1 to length(s1)do
    if (s1[i]<>s2[i])then
      s1[i]:='1'
    else
      s1[i]:='0';
  write(s1);

end.