uses math;
var ans: array[0..1000] of extended;
    num: array[0..1000] of longint;
    i,j,n,a,y,b,t1,t2,k: longint;
procedure sort(l,r: longint);
      var
         i,j,z: longint;
         x,y: extended;
      begin
         i:=l;
         j:=r;
         x:=ans[(l+r) div 2];
         repeat
           while (ans[i]>x) do
            inc(i);
           while (x>ans[j]) do
            dec(j);
           if not(i>j) then
             begin
                y:=ans[i];
                ans[i]:=ans[j];
                ans[j]:=y;
                z:=num[i];
                num[i]:=num[j];
                num[j]:=z;
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
   Read(n,t1,t2,k);
   For i:=1 to n do
     begin
        read(a,b);
        num[i]:=i;
        ans[i]:=max((((t1*a)/100)*(100-k))+(t2*b),(((t1*b)/100)*(100-k))+(t2*a));
     end;
   Sort(1,n);
   For i:=1 to n do
    begin
     For j:=1 to i-1 do
      begin
       if (ans[i]=ans[j]) and (num[i]<num[j]) then
        begin
         y:=num[i];
         num[i]:=num[j];
         num[j]:=y;
        end;
      end;
    end;
   For i:=1 to n do
      Writeln(num[i],' ',ans[i]:0:2);
  End.