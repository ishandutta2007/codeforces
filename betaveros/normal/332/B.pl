# betaveros's polyglot adventures
use strict;
use warnings;

my ($nLaws, $seglen) = split(' ', <STDIN>);
my @absurdities = split(' ', <STDIN>);

my @cumsums = (0);

my $tempsum = 0;
foreach (@absurdities) {
	$tempsum += $_;
	push @cumsums, $tempsum;
}

my @segments = ();
my @maxsums = ();
my @maxis = ();

my $maxsum = 0;
my $maxi = 0;
foreach my $i (0 .. (scalar @absurdities) - $seglen) {
	my $segsum = $cumsums[$i + $seglen] - $cumsums[$i];
	push @segments, $segsum;
	if ($segsum > $maxsum) {
		$maxi = $i;
		$maxsum = $segsum;
	}
	push @maxsums, $maxsum;
	push @maxis, $maxi;
}

my $maxsign = 0;
my $maxsi1 = 0;
my $maxsi2 = 0;
foreach my $i ($seglen .. (scalar @absurdities) - $seglen) {
	my $signsum = $maxsums[$i - $seglen] + $segments[$i];
	if ($signsum > $maxsign) {
		$maxsign = $signsum;
		$maxsi1 = $maxis[$i - $seglen];
		$maxsi2 = $i;
	}
} 
print ($maxsi1 + 1, " ", $maxsi2 + 1);