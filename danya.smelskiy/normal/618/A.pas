var q,w,e,r,t,y,u,i,o,p: longint;
     Begin
        Read(q);
        While q<>0 do
            begin
             w:=1;
             e:=1;
             While e<=q do
                begin
                  Inc(w);
                  e:=e*2;
                end;
                if e=q then
                begin
                Write(w,' ');
                Halt;
                end
                else Write(w-1,' ');
                Dec(q,e div 2);
            end
     End.