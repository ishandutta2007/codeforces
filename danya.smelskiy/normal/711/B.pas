var a,b: array[0..500] of int64;
   n,i,j,a1,a2: longint;
   x,ans,first,second: int64;
   Begin
    Read(n);
    if n=1 then
     begin
      write(1);
      halt;
     end;
    For i:=1 to n do
     begin
      For j:=1 to n do
       begin
        read(x);
        inc(a[i],x); inc(b[j],x); if i=j then inc(first,x);
        if (i=(n-j+1)) then inc(second,x);
        if x=0 then
         begin
          a1:=i;
          a2:=j;
         end;
       end;
     end;
     if a[a1]<>b[a2] then
      begin
       write('-1');
       halt;
      end
     else
      begin
       for i:=1 to n do
        begin
        for j:=1 to n do
         if (i<>a1) and (j<>a2) then break;
         if (i<>a1) and (j<>a2) then break;
        end;
       ans:=a[i]-a[a1];
       if ans<=0 then
        begin
         write('-1');
         halt;
        end
       else
        begin
         inc(a[a1],ans);
         inc(b[a2],ans);
         if a1=a2 then inc(first,ans);
         if (a1=(n-a2)+1) then inc(second,ans);
        for i:=1 to n do
         begin
          for j:=1 to n do
           begin

            if (a[i]<>b[j]) or (a[i]<>first) or (b[j]<>first) or (a[i]<>second) or (b[j]<>second) then
            begin
             write('-1');
             halt;
            end;
           end;
          end;
         end;
         end;
 {   else
      begin
      write('-1');
      halt;
      end;   }
      write(ans);
   End.