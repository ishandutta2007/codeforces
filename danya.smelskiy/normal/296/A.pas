var a,b: array[0..1000] of longint;
  i,j,n: longint;
  Begin
   Read(n);
   For i:=1 to n do
    begin
      Read(a[i]);
      inc(b[a[i]]);
    end;
   For i:=1 to n do
   begin
      if (n mod 2=0) then if (b[a[i]]>(n div 2)) then
       begin
        Write('NO');
        halt;
       end;
      if ( n mod 2=1) then if  (b[a[i]]>(n div 2)+1) then
       begin
        Write('NO');
        halt;
       end;
   end;
   Write('YES');
  End.