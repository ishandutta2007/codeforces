var f, l, n, i : longint;
    s : string;
begin
readln(n);
for i := 1 to n do
begin
  readln(s);
  f := 0;
  l := length(s);
  if (l > 4) and (s[l] = '.') and (s[l - 1] = 'a') and (s[l - 2] = 'l') and (s[l - 3] = 'a') and (s[l - 4] = 'l') then f := 1;
  if (l > 4) and (s[1] = 'm') and (s[2] = 'i') and (s[3] = 'a') and (s[4] = 'o') and (s[5] = '.') then f := f + 10;
  if f = 1 then writeln('Freda', chr(39), 's');
  if f = 10 then writeln('Rainbow', chr(39), 's');
  if (f = 0) or (f = 11) then writeln('OMG>.< I don', chr(39), 't know!');
end;
end.