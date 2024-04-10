#!/usr/bin/perl -w
my $x = <STDIN>;
my $a = '';
my $b = 2;
my $t = 3;
if ($x % $b != 0){
    $x = $x - $t;
    print '7';
}
while ($x > 0){
    $x = $x - $b;
    print '1';
}