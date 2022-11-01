var n,c,i,j,k,kol:longint;
    s:ansistring;
begin
readln(s);
kol:=0;
while (length(s)>=0)and(pos('bear',s)>0)do begin
      c:=pos('bear',s);
      kol:=kol+c*(length(s)-c-2);
      delete(s,1,c);
end;
writeln(kol);
end.