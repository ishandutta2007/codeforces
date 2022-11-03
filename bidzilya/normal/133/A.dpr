program task_a;

{$APPTYPE CONSOLE}

var s: string;
    i: integer;
begin
  readln(s);
  for i:=1 to length(s)do
    if (s[i]='H')or(s[i]='Q')or(s[i]='9')then begin
      writeln('YES');
      halt;
    end;
  writeln('NO');
end.