uses SysUtils;
var
  j,n:integer;
  s:string;
  bol:boolean;
  
begin
  readln(n);
  s:=inttostr(n);;
  while n>1 do begin
    bol:=false;
    for j:=2 to n div 2 do
      if n mod j=0 then begin n:=n div j; bol:=true; s:=s+' '+inttostr(n); break; end;
    if bol=false then begin n:=1; s:=s+' 1'; end;
  end;
  writeln(s);
end.