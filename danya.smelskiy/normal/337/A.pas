var a: array[1..50] of longint;
  n,m,i,min: longint;
  procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
   Begin
      Read(n,m);
      For i:=1 to m do
        Read(a[i]);
        Sort(1,m);
        min:=100000;
      For i:=1 to m-n+1 do
         begin
          if a[i+n-1]-a[i]<min then min:=a[i+n-1]-a[i];
         end;
         Write(min);
   End.