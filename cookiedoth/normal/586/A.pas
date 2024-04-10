program Task_A;
var
   n,i,c,kp,k0:Integer;
   one:Boolean;
begin
   Readln(n);
   kp:=0;
   k0:=0;
   one:=false;
   for i:=1 to n do
   begin
     Read(c);
     inc(kp);
     if c=0 then inc(k0);
     if c=1 then
     begin
        if one=true then
        begin
          if k0>1 then dec(kp,k0);
        end;
        if one=false then
        begin
          one:=true;
          dec(kp,kp-1);
        end;
        k0:=0;
     end;
   end;
   dec(kp,k0);
   Writeln(kp);
end.