program A75;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a, b, c:int64;
    i:integer;
    sa, sb, ta, tb, sc, tc:string;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  readln(a, b);
  c := a + b;
  sa := inttostr(a);
  sb := inttostr(b);
  sc := inttostr(c);
  ta := '';
  tb := '';
  tc := '';
  for i := 1 to length(sa) do
    if(sa[i] <> '0') then
      ta := ta + sa[i];
  for i := 1 to length(sb) do
    if(sb[i] <> '0') then
      tb := tb + sb[i];
  for i := 1 to length(sc) do
    if(sc[i] <> '0') then
      tc := tc + sc[i];
  a := strtoint(ta);
  b := strtoint(tb);
  c := strtoint(tc);
  if(a + b = c) then
    writeln('YES')
  else
    writeln('NO');
end.