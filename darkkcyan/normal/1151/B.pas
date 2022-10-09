uses math;

const maxn = 555;
var n, m: longint;
var a: array[0..maxn, 0..maxn] of longint;
var i, f, g: longint;
var x1: longint;
var has_diff: boolean;

begin
  read(n, m);
  for i := 1 to n do
    for f := 1 to m do begin
      read(a[i][f]);
    end;
  x1 := 0;
  for i := 1 to n do x1 := x1 xor a[i][1];
  if x1 <> 0 then begin
    writeln('TAK');
    for i := 1 to n do write('1 ');
    halt();
  end;

  for i := 1 to n do begin
    has_diff := false;
    for f := 2 to m do begin
      if a[i][f] <> a[i][1] then begin
        has_diff := true;
        break;
      end;
    end;
    if not has_diff then continue;
    writeln('TAK');
    for g := 1 to n do 
      if g <> i then write(1, ' ')
      else writeln(f, ' ');
    halt;
  end;
  writeln('NIE');
end.