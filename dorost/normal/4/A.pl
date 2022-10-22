use strict;
use warnings;
use utf8;
use 5.012;
my $n = <>;
chomp($n);
if($n > 2 && $n % 2 == 0){
  say "YES";
}else {
  say "NO";
}