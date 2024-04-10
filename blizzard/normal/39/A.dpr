{$Apptype console}
uses
  SysUtils;

type sl = record
  f : boolean; //f = ++a
  k : longint;
end;
t1 = array[0..10000] of sl;

var s : string;
    a : t1;
    n, i, m, r, ans, p, j, last : longint;

procedure qsort(l, r : longint);
var i, j, m : longint;
    ob : sl;
begin
  if l >= r then
    exit;
  i := l;
  j := r;
  m := a[(l + r) div 2].k;
  while i <= j do begin
    while a[i].k < m do inc(i);
    while a[j].k > m do dec(j);
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
  readln(p);
  readln(s);
  i := 1;
  n := length(s);
  m := 0;
  last := 0;
  while i <= n do begin
    if s[i] = 'a' then begin
      if i = 1 then begin
        inc(m);
        a[m].f := false;
        a[m].k := 1;
        last := i + 2;
        i := i + 3;
        continue;
      end;
      if s[i - 1] = '*' then begin
        inc(m);
        j := i - 2;
        r := 1;
        while (j > 0) and (s[j] >= '0') and (s[j] <= '9') do begin
          a[m].k := a[m].k  + r * (ord(s[j]) - ord('0'));
          r := r * 10;
          dec(j);
        end;
        if (j > 0) then
          if s[j] = '-' then
            a[m].k := -a[m].k;
        a[m].f := false;
        last := i + 2;
        i := i + 3;
        continue;
      end;
      if (last = i - 2) then begin
        inc(m);
        a[m].f := false;
        a[m].k := 1;
        if s[i - 1] = '-' then
          a[m].k := -1;
        last := i + 2;
        i := i + 3;
        continue;
      end;
      inc(m);
      a[m].f := true;
      if s[i - 3] <> '*' then begin
        if s[i - 3] = '-' then
          a[m].k := -1
        else
          a[m].k := 1;
        last := i;
        inc(i);
        continue;
      end;
      j := i - 4;
      r := 1;
      while (j > 0) and (s[j] >= '0') and (s[j] <= '9') do begin
        a[m].k := a[m].k  + r * (ord(s[j]) - ord('0'));
        r := r * 10;
        dec(j);
      end;
      if (j > 0) then
        if s[j] = '-' then
          a[m].k := -a[m].k;
      last := i;
      i := i + 1;
      continue;
    end else
      inc(i);
  end;
  qsort(1, m);
  ans := 0;
  for i := 1 to m do
    if a[i].f then begin
      inc(p);
      ans := ans + p * a[i].k;
    end else begin
      ans := ans + p * a[i].k;
      inc(p);
    end;
  write(ans);
  {close(output); }
end.