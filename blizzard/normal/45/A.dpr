{$Apptype console}
var s : string;
    k, i : longint;
const a : array [1..12] of string = ('January', 'February', 'March', 'April', 'May',
 'June', 'July', 'August', 'September', 'October', 'November', 'December');
begin
  readln(s);
  read(k);
  k := k mod 12;
  for i := 1 to 12 do if a[i] = s then break;
  k := (i + k) mod 12;
  if k = 0 then k := 12;
  write(a[k]);
end.