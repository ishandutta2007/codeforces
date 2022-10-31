var
k,t: boolean;
s1,s2: ansistring;
i,j,n,a,b: longint;
  Begin
   Readln(s1);
   Readln(s2);
   if length(s1)<>length(s2) then
   begin
    Write('NO');
    halt;
   end;
   For i:=1 to length(s1) do
     begin
        if (s1[i]<>s2[i]) and (t=false) then
        begin
         t:=true;
         a:=i;
        end
        else if (s1[i]<>s2[i]) and (t=true) then
         begin
          if k=true then
            begin
             Write('NO');
             halt;
            end;
            k:=true;
            b:=i;
         end;
     end;
     if (a<>0) and (b<>0) then
      begin
     if (s1[a]=s2[b]) and (s1[b]=s2[a]) then
      begin
       Write('YES');
       Halt;
      end;
      end;
      if s1=s2 then
       begin
     For i:=1 to length(s1) do
      begin
       For j:=1 to i-1 do
        begin
         if (s1[i]=s1[j]) then
           begin
            Write('YES');
            halt;
           end;
        end;
        end;
      end;
      Write('NO');
  End.