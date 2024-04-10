const month:array[1..12] of string =('January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December');

var
  s:String;
  k,i,j:integer;
  
begin
  readln(s);
  read(k);
  for i:=1 to 12 do
    if month[i]=s then begin j:=i; break; end;
  j:=j+k;
  j:=j mod 12;
  if j=0 then j:=12;
  writeln(month[j]);
end.