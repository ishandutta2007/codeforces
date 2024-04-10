var
  m: array [1..100000] of longint;
  n, i, max, t, l: longint;

begin
  read(n);
  for i := 1 to n do
    read(m[i]);
  t := 3;
  max := 2;
  while t <= n do
    if m[t] = m[t - 1] + m[t - 2] then
    begin
      l := 3;
      t := t + 1;
      while (m[t] = m[t - 1] + m[t - 2]) and (t <= n) do
      begin
        l := l + 1;
        t := t + 1;
      end;
      if l > max then max := l;
    end
    else t := t + 1;
  if n = 1 then writeln(1) else writeln(max);
end.