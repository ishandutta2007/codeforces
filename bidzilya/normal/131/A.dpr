program task_a;

{$APPTYPE CONSOLE}

var s: string;
    i: integer;
    ok: boolean;
function rev(c: char): char;
begin
  if ( c in['a'..'z'])then rev:=chr(ord(c)-32)
  else rev:=chr(ord(c)+32);
end;
begin
  readln(s);
  ok:=true;
  for i:=2 to length(s)do
    if (s[i]in ['a'..'z'])then begin
      ok:=false;
      break;
    end;
  if (ok)then
    for i:=1 to length(s)do
      s[i]:=rev(s[i]);
  writeln(s);
end.