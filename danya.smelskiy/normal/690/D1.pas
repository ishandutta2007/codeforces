var a: array[0..100,0..100] of char;
   i,j,n,m,ans: longint;
   k: boolean;
   Begin
    Readln(n,m);
    For i:=1 to n do
     begin
      For j:=1 to m do
        begin
              read(a[i,j]);
        end;
        readln;
     end;
     k:=true;
     if (a[n,1]='B') then inc(ans);
    For j:=1 to m do
      begin
       if (k=true) and (a[n,j]='.') then k:=false;
       if (k=false) and (a[n,j]='B') then
           begin
            inc(ans);
            k:=true;
           end;
      end;
      Write(ans);
   End.