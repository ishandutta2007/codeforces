{$apptype console}
{$O-}
var
   i,j,n : longint;
   ob : string;
   c : char;
   ff : boolean;
   koln,kolf : array['A'..'Z'] of longint;
   f : array[0..1000] of boolean;
   fam : array[0..1000] of longint;
   name,famil : array[0..300] of string;
procedure sort1(n : longint);
var
   i : longint;
   f : boolean;
begin
   repeat
      f := true;
      for i := 1 to n - 1 do
         if name[i] > name[i+1] then
         begin
            ob := name[i];
            name[i] := name[i+1];
            name[i+1] := ob;
            f := false;
         end;
   until f;
end;
procedure sort2(n : longint);
var
   i : longint;
   f : boolean;
begin
   repeat
      f := true;
      for i := 1 to n - 1 do
         if famil[i] > famil[i+1] then
         begin
            ob := famil[i];
            famil[i] := famil[i+1];
            famil[i+1] := ob;
            f := false;
         end;
   until f;
end;
procedure sort3(n : longint);
var
   i : longint;
   f : boolean;
begin
   repeat
      f := true;
      for i := 1 to n - 1 do
         if name[i] > name[i+1] then
         begin
            ob := name[i];
            name[i] := name[i+1];
            name[i+1] := ob;
            f := false;
            writeln('');
         end;
   until f;
end;
begin                   {
   reset(input,'input.txt');
   rewrite(output,'output.txt');  }
   readln(n);
   for i := 1 to n do
      readln(name[i]);
   for i := 1 to n do
      readln(famil[i]);
   sort1(n);
   sort2(n);
   for i := 1 to n do
   begin
      f[i] := false;
      fam[i] := 0;
   end;
   for c := 'A' to 'Z' do
   begin
      koln[c] := 0;
      kolf[c] := 0;
   end;
   for i := 1 to n do
      inc(koln[name[i,1]]);
   for i := 1 to n do
      inc(kolf[famil[i,1]]);
   for i := 1 to n do
   begin
      ff := true;
      if koln[name[i,1]] <= kolf[name[i,1]] then
        for j := 1 to n do
         if (name[i,1] = famil[j,1]) and (f[j] = false) then
         begin
            f[j] := true;
            fam[i] := j;
            ff := false;
            dec(koln[name[i,1]]);
            dec(kolf[famil[j,1]]);
            break;
         end;
     { for j := 1 to n do
         if ((name[i,1] = famil[j,1]) and (f[j] = false)) or
         ((kolf[famil[j,1]] - koln[famil[j,1]] >= 1) and (f[j] = false)) then
         begin
            f[j] := true;
            fam[i] := j;
            ff := false;
            dec(koln[name[i,1]]);
            dec(kolf[famil[j,1]]);
            break;
         end; }
      if ff then
      for j := 1 to n do
         if (( (kolf[famil[j,1]] - koln[famil[j,1]] >= 1) and (famil[j,1] <> name[i,1]) ) or (famil[j,1] = name[i,1]) ) and (f[j] = false) then
         begin
            f[j] := true;
            fam[i] := j;
            dec(koln[name[i,1]]);
            dec(kolf[famil[j,1]]);
            break;
         end;
   end;        {
   for i := 1 to n do
      if fam[i] = 0 then
         for j := 1 to n do
            if f[j] = false then
            begin
               f[j] := true;
               fam[i] := j;
               break;
            end;  }
   for i := 1 to n do
      name[i] := name[i] + ' ' + famil[fam[i]];      {
   sort3(n);                                        }
   for i := 1 to n-1 do
      write(name[i],', ');
   write(name[n]);
end.