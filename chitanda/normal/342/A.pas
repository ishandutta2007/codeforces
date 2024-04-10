var
  b:array[0..7]of longint;
  i,j,n,t1,t2,t3:longint;
procedure ed;
begin
  writeln(-1);
  halt;
end;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(j);
    inc(b[j]);
  end;
  if b[5]>0 then ed;
  if b[7]>0 then ed;
  dec(b[1],b[3]);
  dec(b[6],b[3]);   t1:=b[3];
  if b[1]<0 then ed;
  if b[6]<0 then ed;
  dec(b[1],b[6]);
  dec(b[2],b[6]);   t2:=b[6];
  if b[1]<0 then ed;
  if b[2]<0 then ed;
  if (b[1]<>b[2])or(b[2]<>b[4]) then ed;
  t3:=b[1];
  for i:=1 to t3 do writeln(1,' ',2,' ',4);
  for i:=1 to t2 do writeln(1,' ',2,' ',6);
  for i:=1 to t1 do writeln(1,' ',3,' ',6);
end.