uses SysUtils;
var
  s:string;
  sm,i,j:integer;
  
begin
  //assign(input,'input.txt');
  //reset(input);
  readln(s);
  sm:=0;
  while length(s)>1 do begin
    inc(sm);
    j:=0;
    for i:=1 to length(s) do
      j:=j+ord(s[i])-48;
    s:=inttostr(j);
  end;
  write(sm);
  //close(input);
end.