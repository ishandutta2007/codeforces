var s: string;
    i, a, b, n: integer;
begin
 read(s);
 n:=length(s);
 a:=0;
 b:=0;
 for i:=1 to (n-1) do
  begin
   if (s[i]='V') and (s[i+1]='K') then a:=a+1;   
  end;
 
 if n<3 then 
begin
     if (s[n]='V') and (s[n-1]='V')
       then b:=1;
     if(s[1]='K') and (s[2]='K') then b:=1;
 end
     else  
      for i:=1 to (n-2) do
       begin 
       if (s[n]='V') and (s[n-1]='V') then b:=1;
       if (s[i]='V') and (s[i+1]='V') and (s[i+2]='V') then b:=1;
       if (s[i]='K') and (s[i+1]='K') and (s[i+2]='K') then b:=1;
       if(s[1]='K') and (s[2]='K') then b:=1;
       end;   

 a:=a+b;  
 writeln(a);
 end.