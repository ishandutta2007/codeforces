var a: array[0..100000] of longint;
    n,m,i,j,x,l,r,mid: longint;

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
     Read(n);
     For i:=1 to n do
       read(a[i]);
     sort(1,n);
     read(m);
     For i:=1 to m do
     begin
      read(x);
      l:=1;
      r:=n+1;
      While l<r-1 do
       begin
          mid:=(l+r) div 2;
          if a[mid]<=x then l:=mid
          else r:=mid;
       end;
       if a[l]<=x then writeln(l)
       else Writeln(l-1);
      end;
    End.