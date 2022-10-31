const
   dx : array[1..8] of longint= (1,2,2,1,-1,-2,-2,-1);
   dy : array[1..8] of longint = (2,1,-1,-2,-2,-1,1,2);
var
   i,j,i1,v,j1,i2,j2,kol : longint;
   c1,c2,c3,c4 : char;
   a : array[-10..20,-10..20] of longint;
begin
  read(c1);
  read(c2);
  readln;
  read(c3);
  read(c4);
  i1 := ord(c1) - ord('a') + 1;
  j1 := ord(c2) - 48;
  i2 := ord(c3) - ord('a') + 1;
  j2 := ord(c4) - 48;
  a[i1,j1] := 1;
  for i := 1 to 8 do
     a[i,j1] := 1;
  for j := 1 to 8 do
     a[i1,j] := 1;
  a[i2,j2] := 1;
  for v := 1 to 8 do
  begin
     i := i1 + dx[v];
     j := j1 + dy[v];
     a[i,j] := 1;
     i := i2 + dx[v];
     j := j2 + dy[v];
     a[i,j] := 1;
  end;
  kol := 0;
  for i := 1 to 8 do
     for j:= 1 to 8 do
        if a[i,j] = 0 then inc(kol);
  write(kol);
end.