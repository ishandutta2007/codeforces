program task_b;

{$APPTYPE CONSOLE}
const d: array[1..8]of char = ('>','<','+','-','.',',','[',']');
      b: array[1..8]of string = ('1000','1001','1010','1011','1100','1101','1110','1111');
      md = round(1e6)+3;
var s,tmp: string;
    i,j,ans: integer;
begin
  readln(s);
  ans:=0;
  for i:=1 to length(s)do begin
    for j:=1 to 8 do
      if (s[i]=d[j])then begin
        tmp:=b[j];
        break;
      end;
    for j:=1 to 4 do
      ans:=(ans*2 mod md + ord(tmp[j])-ord('0'))mod md;
  end;
  write(ans);
end.