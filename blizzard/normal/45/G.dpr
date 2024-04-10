{$APPTYPE CONSOLE}
uses
  SysUtils;
type
t = array[0..50000000] of boolean;
t1 = array[0..6000] of longint;
var p, ans : t;
    a : t1;
    i, n, j, x, k, q, y, v : longint;
    ff : boolean;
begin
 { assign(input, 'input.txt');
  assign(output, 'output.txt');
  reset(input);
  rewrite(output);  }
  read(n);
  x := n * (n + 1) div 2;
  p[0] := true;
  p[1] := true;
  for i := 2 to trunc(sqrt(x)) do
    if p[i]  = false then begin
      j := i * 2;
      while j <= x do begin
        p[j] := true;
        j := j + i;
      end;
    end;
  if p[x] = false then begin
    for i := 1 to n do
      write('1 ');
    halt(0);
  end;
  if x mod 2 = 1 then begin
    if p[x - 2] = false then begin
      for i := 1 to n do
        if (i <> 2) then
          write('1 ')
        else
          write('2 ');
    end else begin
      y := x;
      for i := n downto 2 do
        if p[i] = false then begin
          inc(q);
          a[q] := i;
        end;
      q := 0;
      while ff = false do begin
        fillchar(ans, sizeof(ans), false);
        ff := true;
        inc(q);
        x := y - a[q];
        for i := 2 to x div 2 do
          if (p[i] = false) and (p[x - i] = false) then begin
            v := i;
            break;
          end;
        k := 0;
        while v > n - k do begin
          if n - k = a[q] then begin
            ff := false;
            break;
          end;
          ans[n - k] := true;
          v := v - n  + k;
          dec(k);
        end;
        if ff = false then continue;
        if (v <= n - k) and (v > 0) then begin
          if v = a[q] then begin
            ff := false;
            break;
          end;
          ans[v] := true;
        end;
        if ff = false then continue;
        for i := 1 to n do
          if i = a[q] then
            write('3 ')
          else if
          ans[i] then
            write('1 ')
          else
            write('2 ');
      end;
    end;
    halt(0);
  end;
  for i := 2 to x div 2 do
    if (p[i] = false) and (p[x - i] = false) then begin
      v := i;
      break;
    end;
  k := 0;
  while v > n - k do begin
    ans[n - k] := true;
    v := v - n  + k;
    dec(k);
  end;
  if (v <= n - k) and (v > 0) then
    ans[v] := true;
  for i := 1 to n do
    if ans[i] then
      write('1 ')
    else
      write('2 ');
end.