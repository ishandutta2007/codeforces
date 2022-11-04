program A186;
var n:integer;
begin

  readln(n);
  if n>=0 then writeln(n)
  else
  begin
    n:=-n;
    if (n mod 10) * 11> n mod 100 then writeln(-(n div 10))
    else writeln(-((n div 100) * 10 + (n mod 10)));
  end;
end.