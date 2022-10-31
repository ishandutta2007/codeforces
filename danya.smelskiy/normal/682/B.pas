var a: array[1..100000] of int64;
    i,j,n: longint;
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
      Read(a[i]);
     Sort(1,n);
     a[1]:=1;
     For i:=2 to n do
        begin
         if a[i]-a[i-1]>1 then dec(a[i],a[i]-a[i-1]-1);
        end;
        Write(a[n]+1);
    End.