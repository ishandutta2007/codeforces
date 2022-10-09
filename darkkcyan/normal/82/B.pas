uses math;
const maxn = 210;
var
  n: longint;
  pos: array[0..maxn * maxn] of longint;
  a: array[0..maxn * maxn] of longint;

procedure enter;
var i, f, l: longint;
begin
  read(n);
  pos[1] := 0;
  for i := 1 to n * (n - 1) div 2 do begin
    read(l);
    pos[i + 1] := pos[i] + l;
    for f := pos[i] to pos[i + 1] - 1 do read(a[f]);
  end;
end;

var
  b: array [0..maxn] of longint;
  nb: longint;

procedure fillter;
var i, f: longint;
begin
  nb:= 0;
  for i := 1 to n * (n - 1) div 2 do begin
    for f := pos[i] to pos[i + 1] - 1 do begin
      if a[f] <> a[0] then continue;
      inc(nb);
      b[nb] := i;
      break;
    end;
  end;
end;

procedure process;
var
  cnt: array[0..maxn] of longint;
  i, f, cf: longint;
begin
  if n = 2 then begin
    writeln(1, ' ', a[0]);
    write(pos[2] - pos[1] - 1,' ');
    for i := 1 to pos[2] - 1 do write(a[i], ' ');
    exit;
  end;
  fillchar(cnt, sizeof(cnt), 0);
  for i := 1 to nb do begin
    for f := pos[b[i]] to pos[b[i] + 1] - 1 do
      inc(cnt[a[f]]);
  end;
  cf := 0;
  for i := 0 to maxn do
    if cnt[i] = n - 1 then inc(cf);
  write(cf, ' ');
  for i := 0 to maxn do
    if cnt[i] = n  - 1 then write(i, ' ');
  writeln;
  for i := 1 to nb do begin
    write(pos[b[i] + 1] - pos[b[i]] - cf, ' ');
    for f := pos[b[i]] to pos[b[i] + 1] - 1 do
      if cnt[a[f]] <> n - 1 then write(a[f], ' ');
    writeln;
  end;
end;

begin
  enter;
  fillter;
  process;
end.