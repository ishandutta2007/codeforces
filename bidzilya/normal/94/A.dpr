uses SysUtils;
var
  ans,s,tmp:string;
  a:array[0..9]of string;
  i,j:integer;
begin
  readln(s);
  for i:=1 to 10 do
    readln(a[i-1]);
  ans:='';
  for i:=1 to 8 do begin
    tmp:=copy(s,1,10);
    delete(s,1,10);
    for j:=0 to 9 do
      if a[j]=tmp then begin ans:=ans+inttostr(j);  break; end;
  end;
  writeln(ans);
end.