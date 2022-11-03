program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var s,t: string;
    i: integer;
begin
  readln(s);
  for i:=1 to length(s)do
    if (s[i]>='A')and(s[i]<='Z')then
      s[i]:=chr(ord(s[i])+32);
  t:='';
  for i:=1 to length(s)do
    if (s[i]='a')or(s[i]='o')or(s[i]='y')or(s[i]='e')or(s[i]='u')or(s[i]='i')then
      continue
    else
      t:=t+'.'+s[i];
  writeln(t);
end.