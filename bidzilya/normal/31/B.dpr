{$APPTYPE CONSOLE}

var s:string;
    l,i,j:integer;
    ind:array[0..201]of integer;
begin
  readln(s); l:=0;
  for i:=1 to length(s)do
    if s[i]='@'then
    begin
      inc(l);
      ind[l]:=i;
    end;
  ind[l+1]:=length(s)+2;
  ind[0]:=-1;
  if (l=0)then begin writeln('No solution'); halt; end;
  for i:=1 to l+1 do
    if (ind[i]-ind[i-1]<3)then begin writeln('No solution'); halt; end;
  for i:=1 to l do begin
    for j:=ind[i-1]+2 to ind[i]+1 do write(s[j]);
    if (i<>l)then write(',');
  end;
  for i:=ind[l]+2 to length(s) do write(s[i]);
end.