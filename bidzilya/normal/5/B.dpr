var
  s:string;
  a:array[1..1000] of string;
  b:array[1..1000] of integer;
  mn,j,k,i,l:integer;
  bol:boolean;
begin
  i:=0;
  mn:=0;
  while not eof do begin
    inc(i);
    readln(s);
    b[i]:=length(s);
    if b[i]>mn then mn:=b[i];
    a[i]:=s;
  end;
  for j:=0 to mn do
    write('*');
  writeln('*');
  bol:=true;
  for j:=1 to i do begin
    write('*');
    k:=mn-b[j];
    if k mod 2=1 then begin
      if bol then begin  
        for l:=1 to k div 2 do
          write(' ');
        k:=k-(k div 2);
      end;
      if not bol then begin
        for l:=1 to (k div 2)+1 do
          write(' ');
        k:=k-1-(k div 2);
      end;
      bol:=not bol;
    end else begin for l:=1 to k div 2 do write(' '); k:=k div 2; end;
    write(a[j]);
    for l:=1 to k do
      write(' ');
    writeln('*');
   end;
   for i:=0 to mn+1 do
    write('*');
end.