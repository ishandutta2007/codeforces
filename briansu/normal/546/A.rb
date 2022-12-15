s=gets.chop
k,n,w=s.split(" ").map(&:to_i)
t=(1+w)*w/2*k
puts [0,t-n].max