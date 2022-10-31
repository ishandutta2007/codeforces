{$Apptype console}
uses
  SysUtils;
type q = record
  l, len, num : longint;
end;
t = array[0..1000] of q;
t1 = array[0..1000] of boolean;
t2 = array[0..1000] of longint;

var a : t;
    b : t1;
    k, ans : t2;
    i, j, n, x, y, fin, d, l, v : longint;

function less(a, b : q) : boolean;
begin
  less := (a.l < b.l) or ((a.l = b.l) and (a.len < b.len));
end;

procedure qsort(l, r : longint);
var i, j : longint;
    ob, m  : q;
begin
  if l >= r then exit;
  i := l;
  j := r;
  m := a[(l + r) div 2];
  while i <= j do begin
    while less(a[i], m) do inc(i);
    while less(m, a[j]) do dec(j);
    if i <= j then begin
      ob := a[i];
      a[i] := a[j];
      a[j] := ob;
      inc(i);
      dec(j);
    end;
  end;
  qsort(l, j);
  qsort(i, r);
end;

begin
 { assign(input, 'input.txt');
  assign(output, 'output.txt');
  reset(input);
  rewrite(output); }
  read(n);
  for i := 1 to n do begin
    read(x, y);
    a[i].l := x;
    a[i].len := y - x;
    a[i].num := i;
  end;
  qsort(1, n);
  I := 1;
  while i <= n do begin
    j := i;
    while a[j].l = a[j + 1].l do begin
      inc(k[i]);
      b[j] := true;
      b[j + 1] := true;
      inc(j);
    end;
    if j = n then
      fin := i;
    i := j + 1;
  end;
  for i := 1 to n do begin
    if (k[i] > 0) and (fin <> i) then begin
      d := a[i + k[i] + 1].l - a[i].l;
      if k[i] < d then
        for j := 0 to k[i] do begin
          ans[a[i + j].num] := a[i].l + j;
          b[i + j] := true;
        end
      else begin
        for j := 0 to d - 1 do begin
          ans[a[i + j].num] := a[i].l + j;
          b[i + j] := true;
        end;
        for j := d to k[i] do begin
          a[i + j].l := a[i + k[i] + 1].l;
          dec(a[i + j].len, d);
        end;
        l := i + k[i] + 1;
        if fin = l then
          fin := i + d;
        v := k[l];
        k[l] := 0;
        qsort(i + d, l + v);
        k[d + i] := v +  l - i - d;
      end;
      continue;
    end;
    if (k[i] = 0) and (b[i] = false) then begin
      ans[a[i].num] := a[i].l;
      b[i] := true;
      continue;
    end;
    if (k[i] > 0) and (fin = i) then begin
      for j := 0 to k[i] do begin
        ans[a[i + j].num] := a[i].l + j;
        b[i + j] := true;
      end;
      continue;
    end;
  end;
  for i := 1 to n do
    write(ans[i], ' ');
 { close(output); }
end.