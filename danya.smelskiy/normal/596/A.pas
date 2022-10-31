uses math;
var a,b,c,d,e,f,t,y: longint;
    u: array[-1000..1000] of Longint;
    i: array[-1000..1000] of Longint;
    Begin
     d:=0;
     Read(a);
     For b:=1 to a do
      begin
       Read(u[b],i[b]);
       For c:=1 to b do
        if ((u[b]<>u[c]) and (i[b]<>i[c])) then
        begin
        d:=1;
        u[5]:=u[b];
        u[6]:=u[c];
        i[5]:=i[b];
        i[6]:=i[c];
        end;
      end;
     if a=1 then
     begin
     Write('-1');
     Halt;
     end;
     if d=0 then
     begin
     Write('-1');
     Halt;
     end
     else
     begin
      Write((max(u[5],u[6])-min(u[5],u[6]))*(max(i[5],i[6])-min(i[5],i[6])));
     end;
     End.