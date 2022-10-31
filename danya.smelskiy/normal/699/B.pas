var a: array[0..1000,0..1000] of char;
b,c: array[0..1000] of longint;
   n,m,i,j,mid,ans: longint;
  Begin
   Readln(n,m);
   For i:=1 to n do
    begin
      FOr j:=1 to m do
      begin
       read(a[i,j]);
       if a[i,j]='*' then inc(b[i]);
       if a[i,j]='*' then inc(c[j]);
       if a[i,j]='*' then inc(ans);
      end;
      readln;
    end;
   For i:=1 to n do
   begin
      For j:=1 to m do
       begin
        mid:=b[i]+c[j];
        if a[i,j]='*' then dec(mid);
        if mid=ans then
         begin
          Writeln('YES');
          Write(i,' ',j);
          halt;
         end;
       end;
   end;
   Writeln('NO');
  End.