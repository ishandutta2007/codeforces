var a,b,c: longint;
    Begin
     Read(a);
     b:=a div 5;
     if a mod 5>0 then Inc(b);
     Write(b);
    End.