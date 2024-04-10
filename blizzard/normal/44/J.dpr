{$Apptype console}
uses
  SysUtils;
var kb, kw, i, j, n, m : longint;
    a, a1 : array [-1..2000, -1..2000] of char;
    c : char;
    f : boolean;
function getcolor(i, j, k : longint) : char;
begin
  if k = 2 then
    begin
      if (a[i - 1, j] <> 'a') and (a[i + 3, j] <> 'a') and (a[i, j - 1] <> 'a') and (a[i, j + 1] <> 'a') and (a[i + 1, j - 1] <> 'a') and
       (a[i + 1, j + 1] <> 'a') and (a[i + 2, j - 1] <> 'a') and (a[i + 2, j + 1] <> 'a') then getcolor := 'a' else

      if (a[i - 1, j] <> 'b') and (a[i + 3, j] <> 'b') and (a[i, j - 1] <> 'b') and (a[i, j + 1] <> 'b') and (a[i + 1, j - 1] <> 'b') and
       (a[i + 1, j + 1] <> 'b') and (a[i + 2, j - 1] <> 'b') and (a[i + 2, j + 1] <> 'b') then getcolor := 'b' else

      if (a[i - 1, j] <> 'c') and (a[i + 3, j] <> 'c') and (a[i, j - 1] <> 'c') and (a[i, j + 1] <> 'c') and (a[i + 1, j - 1] <> 'c') and
       (a[i + 1, j + 1] <> 'c') and (a[i + 2, j - 1] <> 'c') and (a[i + 2, j + 1] <> 'c') then getcolor := 'c' else getcolor := 'd';
    end else
    begin
      if (a[i, j - 1] <> 'a') and (a[i, j + 3] <> 'a') and (a[i - 1, j] <> 'a') and (a[i + 1, j] <> 'a') and (a[i - 1, j + 1] <> 'a') and
       (a[i + 1, j + 1] <> 'a') and (a[i + 1, j + 2] <> 'a') and (a[i - 1, j + 2] <> 'a') then getcolor := 'a' else

      if (a[i, j - 1] <> 'b') and (a[i, j + 3] <> 'b') and (a[i - 1, j] <> 'b') and (a[i + 1, j] <> 'b') and (a[i - 1, j + 1] <> 'b') and
       (a[i + 1, j + 1] <> 'b') and (a[i + 1, j + 2] <> 'b') and (a[i - 1, j + 2] <> 'b') then getcolor := 'b' else

      if (a[i, j - 1] <> 'c') and (a[i, j + 3] <> 'c') and (a[i - 1, j] <> 'c') and (a[i + 1, j] <> 'c') and (a[i - 1, j + 1] <> 'c') and
       (a[i + 1, j + 1] <> 'c') and (a[i + 1, j + 2] <> 'c') and (a[i - 1, j + 2] <> 'c') then getcolor := 'c' else  getcolor := 'd';
    end;
end;

begin
  {assign(input, 'input.txt');
  assign(output, 'output.txt');
  reset(input);
  rewrite(output);
  }readln(n, m);
  kb := 0;
  kw := 0;
  for i := 1 to n do
    begin
      for j := 1 to m do
        begin
          read(a[i, j]);
          if a[i, j] = 'b' then a[i, j] := 'l';
          if a[i, j] = 'w' then inc(kw);
        end;
      readln;
    end;
  f := true;
  a1 := a;
  for i := 1 to n do
    begin
      for j := 1 to m do
       if a[i, j] = 'w' then
        begin
          if (j + 2 <= m) and (a[i, j + 1] = 'l') and (a[i, j + 2] = 'w') then
            begin
              a[i, j] := '.' ;
              a[i, j + 1] := '.' ;
              a[i, j + 2]:= '.' ;
            end else
          if (i + 2 <= n) and (a[i + 1, j] = 'l') and (a[i + 2, j] = 'w') then
            begin
              a[i, j] := '.' ;
              a[i + 1, j] := '.' ;
              a[i + 2,j] := '.' ;
            end else f := false;
        end;
    end;
  if f = false then
    begin
      write('NO');
      halt(0);
    end;
  a := a1;

  for i := 1 to n do
    begin
      for j := 1 to m do
       if a[i, j] = 'w' then
        begin
          if (j + 2 <= m) and (a[i, j + 1] = 'l') and (a[i, j + 2] = 'w') then
            begin
              c := getcolor(i, j, 1);
              a[i, j] := c;
              a[i, j + 1] := c;
              a[i, j + 2] := c;
            end else
          if (i + 2 <= n) and (a[i + 1, j] = 'l') and (a[i + 2, j] = 'w') then
            begin
              c := getcolor(i, j, 2);
              a[i, j] := c ;
              a[i + 1, j ] := c;
              a[i + 2, j] := c;
            end;
        end;
    end;
  f := true;
  for i := 1 to n do
    for j := 1 to m do
      if (a[i, j] = 'l') or (a[i, j] = 'w') then f := false;
  if f = false then
    begin
      write('NO');
      halt(0);
    end;
  writeln('YES');
  for i := 1 to n do
    begin
      for j := 1 to m do write(a[i, j]);
      writeln;
    end;
end.