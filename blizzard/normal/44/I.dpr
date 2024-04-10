uses
  SysUtils;
type
per = record
  x, y : byte;
  f : boolean;
end;

t1 = array[0..30] of byte;
t2 = array[0..300000] of t1;
t3 = array[1..10] of t2;

t4 = array[0..300000] of per;
t5 = array[1..10] of t4;

t6 = array[0..20] of longint;

t7 = array[0..30] of byte;
t8 = array[0..30] of t7;

var a : t3;
    c : t5;
    k : t6;
    i, j, n, m, l, ii, jj, q, st, fin : integer;
    kol : t1;
    b : t8;
    
begin
 { assign(input, 'input.txt');
  assign(output, 'output.txt');
  reset(input);
  rewrite(output); }
  read(n);
  a[1, 1, 1] := 1;
  k[1] := 1;
  for i := 2 to n do begin
    a[i, 1] := a[i - 1, 1];
    a[i, 1, i] := i;
    a[i, 2] := a[i - 1, 1];
    a[i, 2, i] := 0;
    a[i, 2, i + 1] := i;
    c[i, 1].x := 1;
    c[i, 1].y := 2;
    c[i, 1].f := true;
    c[i, 2] := c[i - 1, 2];
    k[i] := 2;
    for j := 2 to k[i - 1] do begin
      m := 1;
      for l := 1 to 30 do
        kol[l] := 0;
      for l := 30 downto 1 do
        if a[i - 1, j, l] > 0 then begin
          q := l;
          break;
        end;
      for l := 1 to q do
        if a[i - 1, j, l] > 0 then begin
          inc(kol[m]);
          b[m, kol[m]] := a[i - 1, j, l];
        end
        else
          inc(m);
        
      if j mod 2 = 1 then begin
        st := 1;

        l := st;
        inc(kol[l]);
        b[l, kol[l]] := i;
        inc(k[i]);
        q := 0;
        for ii := 1 to m do begin
          for jj := 1 to kol[ii] do begin
            inc(q);
            a[i, k[i], q] := b[ii, jj]
          end;
          inc(q);
          a[i, k[i], q] := 0;
        end;
        dec(kol[l]);
        c[i, k[i]].x := st;
        c[i, k[i]].f := false;

        for l := 1 to m do begin
          if l = st then
            continue;
          c[i, k[i]].y := l;
          inc(kol[l]);
          b[l, kol[l]] := i;
          inc(k[i]);
          q := 0;
          for ii := 1 to m do begin
            for jj := 1 to kol[ii] do begin
              inc(q);
              a[i, k[i], q] := b[ii, jj]
            end;
            inc(q);
            a[i, k[i], q] := 0;
          end;
          dec(kol[l]);
          c[i, k[i]].x := l;
          c[i, k[i]].f := false;
        end;

        c[i, k[i]].f := false;
        c[i, k[i]].y := m + 1;
        inc(k[i]);
        q := 0;
        for ii := 1 to m do begin
          for jj := 1 to kol[ii] do begin
            inc(q);
            a[i, k[i], q] := b[ii, jj]
          end;
          inc(q);
          a[i, k[i], q] := 0;
        end;
        inc(q);
        a[i, k[i], q] := i;
        c[i, j] := c[i - 1, j];
        continue;
      end;

      fin := 1;
      if c[i - 1, j].f then begin
        fin := c[i - 1, j].x;
        for l := 1 to m do
          if l <> c[i - 1, j].x then begin
            fin := l;
            break;
          end;
      end;

      l := m + 1;
      inc(kol[l]);
      b[l, kol[l]] := i;
      inc(k[i]);
      q := 0;
      for ii := 1 to m + 1do begin
        for jj := 1 to kol[ii] do begin
          inc(q);
          a[i, k[i], q] := b[ii, jj]
        end;
        inc(q);
        a[i, k[i], q] := 0;
      end;
      dec(kol[l]);
      c[i, k[i]].x := m + 1;
      c[i, k[i]].f := true;

      for l := 1 to m do begin
        if l = fin then
            continue;
        c[i, k[i]].y := l;
        inc(kol[l]);
        b[l, kol[l]] := i;
        inc(k[i]);
        q := 0;
        for ii := 1 to m do begin
          for jj := 1 to kol[ii] do begin
            inc(q);
            a[i, k[i], q] := b[ii, jj]
          end;
          inc(q);
          a[i, k[i], q] := 0;
        end;
        dec(kol[l]);
        c[i, k[i]].x := l;
        c[i, k[i]].f := false;
      end;

      l := fin;
      inc(kol[l]);
      b[l, kol[l]] := i;
      inc(k[i]);
      q := 0;
      c[i, k[i]].f := false;
      c[i, k[i]].y := fin;
      for ii := 1 to m do begin
        for jj := 1 to kol[ii] do begin
          inc(q);
          a[i, k[i], q] := b[ii, jj]
        end;
        inc(q);
        a[i, k[i], q] := 0;
      end;
      dec(kol[l]);

      c[i, j] := c[i - 1, j];
    end;
  end;
  writeln(k[n]);
  for i := 1 to k[n] do begin
    for j := 30 downto 1 do
      if a[n, i, j] > 0 then begin
        q := j;
        break;
      end;
    write('{');
    for j := 1 to q do
      if a[n, i, j] > 0 then begin
        write(a[n, i, j]);
        if a[n, i, j + 1] > 0 then
          write(',')
        else
          write('}');
      end else begin
        write(',');
        write('{');
      end;
    writeln;
  end;
end.