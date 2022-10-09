const maxn = 201010;
var
  n: longint;
  i, f: longint;
  a: array[0..maxn] of longint;
  got: array[0..maxn] of boolean;
  u, cnt: longint;

begin
  read(n);
  for i := 1 to n do read(a[i]);
  fillchar(got, sizeof(got), 0);
  f := 1;
  for i := 1 to n do begin
    read(u);
    cnt := 0;
    while not got[u] do begin
      inc(cnt);
      got[a[f]] := true;
      inc(f);
    end;
    write(cnt, ' ');
  end;
end.